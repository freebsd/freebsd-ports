# New ports collection makefile for:	libexo
# Date created:		23 October 2004
# Whom:			Matt Lancereau <ports@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11/libexo/Makefile,v 1.1 2006/10/02 21:05:55 ahze Exp $

PORTNAME=	libexo
PORTVERSION=	0.6.2
PORTREVISION=	1
CATEGORIES=	x11 xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/xfce/exo/${PORTVERSION:R}
DISTNAME=	exo-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Application library for the Xfce environment

BUILD_DEPENDS=	${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI

WRKSRC=		${WRKDIR}/${DISTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/lib//}

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20 gtk20 intltool intlhack pkgconfig \
		desktopfileutils
USE_LDCONFIG=	yes
USE_PERL5=	yes
USE_XFCE=	configenv libutil
USE_XORG=	x11
CONFIGURE_ARGS+=--enable-gio-unix \
		--with-gio-module-dir=${PREFIX}/lib/gio/modules
CONFIGURE_ENV+=	ac_cv_prog_AWK="${AWK}"

OPTIONS=	APIDOCS	"Install api documentation"		off \
		PYTHON	"Enable Python support"			off \
		NLS	"Enable Native Language Support"	on

MAN1=		exo-csource.1 exo-open.1

.include <bsd.port.options.mk>

.if defined(WITHOUT_APIDOCS)
CONFIGURE_ARGS+=--without-html-dir
PLIST_SUB+=	APIDOCS="@comment "
.else
CONFIGURE_ARGS+=--with-html-dir=${PREFIX}/share/gtk-doc/html
PLIST_SUB+=	APIDOCS=""
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
CONFIGURE_ARGS+=--enable-python
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}gtk>=2:${PORTSDIR}/x11-toolkits/py-gtk2
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}gtk>=2:${PORTSDIR}/x11-toolkits/py-gtk2
PLIST_SUB+=	PYTHON="" EXODIR="exo-0.6"
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
	@-update-desktop-database

.include <bsd.port.mk>
