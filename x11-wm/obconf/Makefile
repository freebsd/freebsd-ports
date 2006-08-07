# New ports collection makefile for:	obconf
# Date created:				2002-10-13
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	obconf
PORTVERSION=	1.6
CATEGORIES=	x11-wm
MASTER_SITES=	http://tr.openmonkey.com/files/obconf/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Preferences manager for the Openbox window manager

LIB_DEPENDS=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification \
		obparser.2:${PORTSDIR}/x11-wm/openbox

USE_X_PREFIX=	yes
USE_GNOME=	gnomehier gnometarget libglade2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/openbox

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

PORTDOCS=	ABOUT-NLS AUTHORS README TODO
PLIST_FILES=	bin/obconf \
		share/applications/obconf.desktop \
		%%DATADIR%%/obconf.glade
PLIST_DIRS=	%%DATADIR%%
PLIST=		${WRKDIR}/pkg-plist

pre-install:
	@${ECHO_CMD} "@dirrmtry share/applications" > ${PLIST}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
