# New ports collection makefile for:	xfce4-conf
# Date created:		28 August 2008
# Whom:			Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfce4-conf
PORTVERSION=	4.8.0
CATEGORIES=	x11 xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
DISTNAME=	xfconf-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	XFce 4 configuration mananger

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehack gtk20 intltool intlhack pkgconfig
USE_LDCONFIG=	yes
USE_XFCE=	configenv libutil
USE_XORG=	x11

CONFIGURE_ARGS=	--enable-gtk-doc-html=no \
		--disable-debug

OPTIONS=	GTKDOC	"install the library documentation"	off \
		PERL	"Install Perl bindings"			off \
		NLS	"Enable Native Language Support"	on

MAN3PREFIX?=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.pre.mk>

.if defined(WITH_PERL)
MAN3=		Xfce4::Xfconf.3
BUILD_DEPENDS+=	p5-ExtUtils-Depends>=0.300:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=1.12:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		p5-Glib2>=1.200:${PORTSDIR}/devel/p5-Glib2
RUN_DEPENDS+=	${BUILD_DEPENDS}
CONFIGURE_ARGS+=--enable-perl-bindings
PLIST_SUB+=	PERLBIND=""
.else
CONFIGURE_ARGS+=--disable-perl-bindings
PLIST_SUB+=	PERLBIND="@comment "
.endif

.if defined(WITH_GTKDOC)
BUILD_DEPENDS+=	gtkdocize:${PORTSDIR}/textproc/gtk-doc
CONFIGURE_ARGS+=--enable-gtk-doc
.else
CONFIGURE_ARGS+=--disable-gtk-doc
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|--module-dir|--module=xfconf &|' \
		${WRKSRC}/docs/reference/Makefile.in

.include <bsd.port.post.mk>
