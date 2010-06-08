# New ports collection makefile for:	libexo
# Date created:		23 October 2004
# Whom:			Matt Lancereau <ports@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11/libexo/Makefile,v 1.1 2006/10/02 21:05:55 ahze Exp $

PORTNAME=	libexo
PORTVERSION=	0.3.107
CATEGORIES=	x11 xfce
DISTNAME=	exo-${PORTVERSION}
MASTER_SITES=	${MASTER_SITE_XFCE}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Terminal library, extensions to Xfce by os-cillation

BUILD_DEPENDS=	${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${DISTNAME}

GNU_CONFIGURE=	yes
INSTALLS_ICONS= yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehack gnometarget gtk20 intltool intlhack pkgconfig
USE_LDCONFIG=	yes
USE_PERL5=	yes
USE_XFCE=	configenv libutil

CONFIGURE_ARGS=	--enable-gtk-doc-html=no \
		--enable-gtk-doc=no \
		--disable-debug

PLIST_SUB=	VERSION="${PORTVERSION:R}"

OPTIONS=	HAL	"Enable HAL support"			on \
		NOTIFY  "Enable notification support"		on \
		PYTHON	"Enable Python support"			off \
		NLS	"Enable Native Language Support"	on

MAN1=		exo-csource.1 exo-open.1

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_HAL)
CONFIGURE_ARGS+=--enable-hal
LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal
.else
CONFIGURE_ARGS+=--disable-hal
.endif

.if !defined(WITHOUT_NOTIFY)
CONFIGURE_ARGS+=--enable-notifications
LIB_DEPENDS+=	notify.1:${PORTSDIR}/devel/libnotify
PLIST_SUB+=	NOTIFY=""
.else
CONFIGURE_ARGS+=--disable-notifications
PLIST_SUB+=	NOTIFY="@comment "
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
CONFIGURE_ARGS+=--enable-python
.include "${PORTSDIR}/Mk/bsd.python.mk"
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}gtk>=2:${PORTSDIR}/x11-toolkits/py-gtk2
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}gtk>=2:${PORTSDIR}/x11-toolkits/py-gtk2
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
	${FIND} ${WRKSRC}/docs/reference -type f -regex '.*\.1' \
	-exec ${INSTALL_MAN} "{}" "${MANPREFIX}/man/man1" \;

.include <bsd.port.post.mk>
