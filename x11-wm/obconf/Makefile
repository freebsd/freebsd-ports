# New ports collection makefile for:	obconf
# Date created:				2002-10-13
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	obconf
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://icculus.org/openbox/obconf/

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Preferences manager for the Openbox window manager

BUILD_DEPENDS=	openbox:${PORTSDIR}/x11-wm/openbox
LIB_DEPENDS=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification

CONFIGURE_ARGS=	--datadir=${PREFIX}/share/openbox --prefix=${PREFIX} \
		--sysconfdir=${PREFIX}/etc/openbox
DOCS=		ABOUT-NLS AUTHORS COPYING README TODO
GNU_CONFIGURE=	yes
PLIST=		${WRKDIR}/pkg-plist
USE_GMAKE=	yes
USE_GNOME=	gtk20 libglade2
USE_X_PREFIX=	yes

pre-configure:
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} 
	@${ECHO_CMD} Waiting ten seconds--press control-C to cancel build.
	@sleep 10

pre-install:
	${ECHO_CMD} bin/obconf > ${PLIST}
	${ECHO_CMD} share/openbox/applications/obconf.desktop >> ${PLIST}
	${ECHO_CMD} share/openbox/obconf/obconf.glade >> ${PLIST}
.if !defined(NOPORTDOCS)
.for ii in ${DOCS}
	${ECHO_CMD} share/openbox/obconf/${ii} >> ${PLIST}
.endfor
.endif
.for ii in share/openbox/applications share/openbox/obconf
	${ECHO_CMD} @dirrm ${ii} >> ${PLIST}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/obconf ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/openbox/applications \
		${PREFIX}/share/openbox/obconf
.if !defined(NOPORTDOCS)
.for ii in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${ii} ${PREFIX}/share/openbox/obconf
.endfor
.endif
	${INSTALL_DATA} ${WRKSRC}/obconf.desktop \
		${PREFIX}/share/openbox/applications
	${INSTALL_DATA} ${WRKSRC}/src/obconf.glade \
		${PREFIX}/share/openbox/obconf

.include <bsd.port.mk>
