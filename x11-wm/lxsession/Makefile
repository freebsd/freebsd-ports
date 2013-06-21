# Created by: chinsan
# $FreeBSD$

PORTNAME=	lxsession
PORTVERSION=	0.4.6.1
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	SF/lxde/LXSession%20%28session%20manager%29/LXSession%20${PORTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	LXDE Session Manager

LIB_DEPENDS=	hal.1:${PORTSDIR}/sysutils/hal
BUILD_DEPENDS=	docbook-to-man:${PORTSDIR}/textproc/docbook-to-man

CONFLICTS=	lxsession-lite-[0-9]*

USE_GNOME=	gtk20 intlhack

USE_GMAKE=	yes
USES=		iconv
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN1=		lxsession.1 lxsession-logout.1

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|po man|man|' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
