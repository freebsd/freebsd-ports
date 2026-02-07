PORTNAME=	xfce4-conf
PORTVERSION=	4.20.0
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE
DISTNAME=	xfconf-${DISTVERSIONFULL}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	D-Bus-based configuration storage system
WWW=		https://gitlab.xfce.org/xfce/xfconf

LICENSE=	GPLv2

USES=		compiler:c11 gettext-tools gmake gnome libtool pathfix perl5 \
		pkgconfig tar:bzip2 xfce xorg
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_XFCE=	libutil
USE_XORG=	x11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-bash-completion-dir \
		--without-html-dir
INSTALL_TARGET=	install-strip

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=		GIR NLS VAPI
OPTIONS_DEFAULT=	GIR VAPI
OPTIONS_SUB=		yes

GIR_DESC=	Use Gobject Introspection

GIR_USE=		GNOME=introspection:build
GIR_CONFIGURE_ON=	--enable-introspection=yes
GIR_CONFIGURE_OFF=	--enable-introspection=no

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

VAPI_IMPLIES=		GIR
VAPI_USES=		vala:build
VAPI_CONFIGURE_ENABLE=	vala

post-patch:
	@${REINPLACE_CMD} -i "" -e 's|SystemdService|#SystemdService|' \
		${WRKSRC}/xfconfd/org.xfce.Xfconf.service.in

.include <bsd.port.mk>
