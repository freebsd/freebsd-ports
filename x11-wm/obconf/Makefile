# Created by: trevor
# $FreeBSD$

PORTNAME=	obconf
PORTVERSION=	2.0.3
PORTREVISION=	8
CATEGORIES=	x11-wm
MASTER_SITES=	http://openbox.org/dist/obconf/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Preferences manager for the Openbox window manager

LIB_DEPENDS=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification \
		obrender.27:${PORTSDIR}/x11-wm/openbox

USE_GNOME=	gnomehier libglade2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OPENBOX_CFLAGS="`pkg-config --cflags obrender-3.5 obt-3.5`" \
		OPENBOX_LIBS="`pkg-config --libs obrender-3.5 obt-3.5`"
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/openbox
MAKE_ARGS=	mkdir_p='${MKDIR}'

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

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
