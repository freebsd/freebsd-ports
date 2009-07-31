# New ports collection makefile for:	obconf
# Date created:				2002-10-13
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	obconf
PORTVERSION=	2.0.3
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://offload1.icculus.org/openbox/obconf/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Preferences manager for the Openbox window manager

LIB_DEPENDS=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification \
		obparser.21:${PORTSDIR}/x11-wm/openbox

USE_GNOME=	gnomehier gnometarget libglade2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/openbox
MAKE_ARGS=	mkdir_p='${MKDIR}'

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

PORTDOCS=	ABOUT-NLS AUTHORS README TODO

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.else
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
