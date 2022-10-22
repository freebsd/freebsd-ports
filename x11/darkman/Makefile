PORTNAME=	darkman
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.0
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Framework for dark-mode and light-mode transitions
WWW=		https://gitlab.com/WhyNotHugo/darkman

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		go:modules
USE_GITHUB=	nodefault
USE_GITLAB=	yes
GH_TUPLE=	adrg:xdg:v0.3.3:adrg_xdg/vendor/github.com/adrg/xdg \
		fsnotify:fsnotify:v1.5.1:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-ini:ini:v1.66.2:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		godbus:dbus:v5.0.4:godbus_dbus_v5/vendor/github.com/godbus/dbus/v5 \
		golang:sys:97ca703d548d:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		magiconair:properties:v1.8.5:magiconair_properties/vendor/github.com/magiconair/properties \
		mitchellh:mapstructure:v1.4.3:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		pelletier:go-toml:v1.9.4:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		sj14:astral:v0.1.2:sj14_astral/vendor/github.com/sj14/astral \
		spf13:afero:v1.6.0:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.4.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.3.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.10.0:spf13_viper/vendor/github.com/spf13/viper \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv
GL_ACCOUNT=	WhyNotHugo
GL_COMMIT=	5f30663e4cee23158978e382eea96d0148cf505d
GO_TARGET=	./cmd/${PORTNAME}
PLIST_FILES=	bin/${PORTNAME} \
		share/bash-completion/completions/${PORTNAME} \
		share/fish/vendor_completions.d/${PORTNAME}.fish \
		share/zsh/site-functions/_${PORTNAME} \
		share/dbus-1/services/nl.whynothugo.darkman.service \
		share/dbus-1/services/org.freedesktop.impl.portal.desktop.darkman.service  \
		share/xdg-desktop-portal/portals/${PORTNAME}.portal

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz

post-patch:
# Respect LOCALBASE for {dark,light}-mode.d scripts
	@${REINPLACE_CMD} 's,/usr/share,${LOCALBASE}/share,' \
		${WRKSRC}/vendor/github.com/adrg/xdg/paths_unix.go

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/dbus-1/services
	${INSTALL_DATA} ${WRKSRC}/contrib/dbus/nl.whynothugo.darkman.service \
		${STAGEDIR}${PREFIX}/share/dbus-1/services/
	${INSTALL_DATA} ${WRKSRC}/contrib/dbus/org.freedesktop.impl.portal.desktop.darkman.service \
		${STAGEDIR}${PREFIX}/share/dbus-1/services/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xdg-desktop-portal/portals
	${INSTALL_DATA} ${WRKSRC}/contrib/portal/${PORTNAME}.portal \
		${STAGEDIR}${PREFIX}/share/xdg-desktop-portal/portals/
.for _shell in bash fish zsh
	@${ECHO_MSG} "Generating ${STAGEDIR}${PREFIX}/${PLIST_FILES:M*${_shell}*}"
	${WRKDIR}/bin/${PORTNAME} completion ${_shell} \
		>${STAGEDIR}${PREFIX}/${PLIST_FILES:M*${_shell}*}
.endfor

do-build-MANPAGES-on:
	scdoc < ${WRKSRC}/${PORTNAME}.1.scd >${WRKSRC}/${PORTNAME}.1

do-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/${MANPAGES_PLIST_FILES:H}

.include <bsd.port.mk>
